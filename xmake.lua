add_rules("mode.debug", "mode.release")

target("Killer7DLL")
    set_kind("shared")
    set_languages("cxx23")
    add_files("src/**.cpp")
    add_includedirs("include")