solution "Pattern"
    configurations { "Debug", "Release" }
    platforms { "native", "x32", "x64" }

    project "test"
        language "C++"
        buildoptions { "-std=c++11" }

        includedirs { "ext/sol/", "ext/BulletLua/include/" }
        files { "src/**" }

        targetdir "bin"
        targetname "Test"

        ---------------------------------------
        -- Link static libraries and config
        libdirs { "ext/BulletLua/lib/" }
        links { "sfml-graphics", "sfml-audio", "sfml-window", "sfml-system",
                "bulletlua", "lua" }

        configuration "linux"
            targetprefix "linux_"

        configuration "windows"
            targetprefix "windows_"

        configuration { "native or x64" }
            targetsuffix "64"

        configuration "x32"
            targetsuffix "32"

        -- Executable should look for shared libraries in its own directory when run.
        configuration "not windows"
            linkoptions { "-Wl,-rpath '-Wl,\$\$ORIGIN'" }

        -- Hacky workaround (combined with the previous link options) so we can
        -- conveniently find our shared library files.
        configuration "not windows"
            postbuildcommands { "cp ext/BulletLua/lib/libbulletlua.so bin" }

        configuration "windows"
            postbuildcommands { "copy ext/BulletLua/lib/BulletLua.dll bin" }

        ---------------------------------------
        -- Build rules
        configuration "Debug"
            kind "ConsoleApp"
            defines "DEBUG"
            flags { "Symbols", "ExtraWarnings" }

        configuration "Release"
            kind "ConsoleApp"
            flags { "Optimize", "ExtraWarnings" }

