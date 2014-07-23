solution "Pattern"
    configurations { "Debug", "Release" }
    platforms { "native", "x32", "x64" }

    project "test"
        language "C++"
        buildoptions { "-std=c++11" }

        -- includedirs { "./src/" }
        files { "src/**" }

        targetdir "bin"
        targetname "Test"

        ---------------------------------------
        -- Link static libraries and config
        links { "sfml-graphics", "sfml-audio", "sfml-window", "sfml-system", "bulletml" }

        configuration "linux"
            targetprefix "linux_"

        configuration "windows"
            targetprefix "windows_"

        configuration { "native or x64" }
            targetsuffix "64"

        configuration "x32"
            targetsuffix "32"

        ---------------------------------------
        -- Build rules
        configuration "Debug"
            kind "ConsoleApp"
            defines "DEBUG"
            flags { "Symbols", "ExtraWarnings" }

        configuration "Release"
            kind "ConsoleApp"
            flags { "Optimize", "ExtraWarnings" }

