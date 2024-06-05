import idaapi
import idc
import idautils
import re
assert_address = 0x42C400 #Address of the assert function

def get_string_at_address(address):
    string = idc.get_strlit_contents(address)
    if type(string) == bytes:
        return string.decode('utf-8')
    return None

# Function to sanitize function names by replacing special characters
def sanitize_function_name(name):
    # Replace characters that are not allowed in IDA names with underscores
    sanitized_name = re.sub(r' ', '_', name)
    return sanitized_name

for xref in idautils.XrefsTo(assert_address, 0):
    print(xref.type, idautils.XrefTypeName(xref.type), 'from', hex(xref.frm), 'to', hex(xref.to))
    call_ea = xref.frm
    func = idaapi.get_func(call_ea)
    if not func:
        continue
    print(f"Function name : {idaapi.get_func_name(call_ea)}")
    dism_addr = call_ea
    insn = idautils.DecodeInstruction(dism_addr)
    if insn.get_canon_mnem() != "call":
        continue
    args = []
    for i in range(3):
        insn = idautils.DecodePrecedingInstruction(dism_addr)
        if insn[0] != None:
            print(hex(insn[0].Op1.value))
            dism_addr -= insn[0].size
            args.append(insn[0].Op1.value)
            string_at_arg = get_string_at_address(insn[0].Op1.value)
            if string_at_arg != None:
                print(f"Argument {i+1} (string): {string_at_arg} {sanitize_function_name(string_at_arg)}")
    
    idc.set_name(func.start_ea,"")
                
        
    print([hex(arg) for arg in args])
    