add_rules("mode.debug", "mode.release")
set_allowedarchs("x86")
add_requires("rcmp")
target("Killer7DLL")
    set_kind("shared")
    set_languages("cxx23")
    add_files("src/**.cpp")
    add_files("extern/**.cpp")
    add_includedirs("extern", "extern/detours/include", "extern/eyestep")
    add_includedirs("include")

    add_linkdirs("extern/detours/x86")
    add_links("detours.lib", "user32")
    add_packages("rcmp")

    after_build(function(target)
        local gamePath = "C:\\Users\\HP\\Downloads\\Killer7 Debug\\Killer7 Debug\\killer7.asi"
        os.cp(target:targetfile(), gamePath)
    end)