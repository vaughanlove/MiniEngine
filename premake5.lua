workspace "MiniEngine"
    architecture "x64"
    
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    files
    {
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "{prj.name}/vendor/spdlog/include",
        "{prj.name}/src"
    }

    links
    {
        "MiniEngine"
    }
    
    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ME_PLATFORM_WINDOWS",
        }
    
    filter "configurations:Debug"
    defines "ME_DEBUG"
    symbols "On"
    
    filter "configurations:Release"
    defines "ME_RELEASE"
    optimize "On"

    filter "configurations:Dist"
    defines "ME_DIST"
    optimize "On"

project "MiniEngine"
    location "MiniEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "mepch.hpp"
    pchsource "MiniEngine/src/mepch.cpp"

    files
    {
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }
    
    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ME_PLATFORM_WINDOWS",
            "ME_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
    defines "ME_DEBUG"
    symbols "On"
    
    filter "configurations:Release"
    defines "ME_RELEASE"
    optimize "On"

    filter "configurations:Dist"
    defines "ME_DIST"
    optimize "On"

