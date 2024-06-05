import idaapi
import idc
import idautils
assert_address = 0x42C400 #Address of the assert function

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
        
    print([hex(arg) for arg in args])
    