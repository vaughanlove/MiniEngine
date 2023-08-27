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
        path.join(_MAIN_SCRIPT_DIR, "MiniEngine/vendor/spdlog/include"),
        path.join(_MAIN_SCRIPT_DIR, "MiniEngine/src"),
    }

    links
    {
        "MiniEngine",
        "glfw3",
        "glfw3dll",
    }

    libdirs
    {
        path.join(_MAIN_SCRIPT_DIR, "depend/glfw-3.3.8/lib-vc2022")
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
        path.join(_MAIN_SCRIPT_DIR, "%{prj.name}/vendor/spdlog/include"),
        path.join(_MAIN_SCRIPT_DIR, "depend/glfw-3.3.8/include"),
    }

    libdirs
    {
        path.join(_MAIN_SCRIPT_DIR, "depend/glfw-3.3.8/lib-vc2022")
    }

    links 
    {
        "glfw3",
        "glfw3dll"
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

