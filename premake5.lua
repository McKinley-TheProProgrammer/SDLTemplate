-- Workspace -----------------------------------------------------------------------------------------------------------
workspace "SDL_Template"      -- Nome do seu workspace
    architecture "x64"  -- x86_64 para LINUX - x32 para arquiteturas de 32 bits - x64 para arquiteturas de 64 bits	
    toolset "gcc"          -- Compilador
    language "C++"         -- Linguagem
    cppdialect "C++20"     -- Versão da linguagem 'equivalente a usar -std=c++17'
    configurations { "debug", "release" } -- Configurações de saída

-- Projeto -------------------------------------------------------------------------------------------------------------
project "SDL_Template"      -- Nome do seu projetopr
    location "./" -- Pasta com o projeto
    kind "ConsoleApp"    -- Tipo de aplicação

    -- Diretório onde os códigos compilados serão gerados.
    -- Nesse caso, o diretório é 'mypremake'.
    targetdir ("%{prj.name}")

    -- Esse será seu executável.
    targetname "%{prj.name}_%{cfg.buildcfg}"
    
    -- Diretório onde os códigos objetos serão gerados
    -- Mesma lógica do targetdir
    objdir ("bin/build/%{prj.name}")

    -- Diretório para buscar arquivos que serão compilados.
    -- '**.hpp' significa que serão compilados todos os arquivos hpp encontrados no diretório especificado.
    files { "%{prj.name}/include/**.hpp", "%{prj.name}/src/**.cpp" }

    -- Diretórios para serem inclusos durante a compilação '-I'.
    -- Ao incluir um diretório, não é preciso especificar o caminho todo a partir do diretório raiz. 
    -- Assim, é possível escrever '#include "myclass.hpp"' ao invés de '#include "include/myclass.hpp"'.
    -- OBSERVAÇÃO: deve-se atualizar o diretório da pasta include da SDL aqui.
    includedirs { "%{prj.name}/include", "%{prj.name}/src", "C:/SDL2/SDL-2.30.1/include", "%{prj.name}/lib/sdl/include", 
    "%{prj.name}/lib/sdl_image/include", "%{prj.name}/lib/sdl_mixer/include", "%{prj.name}/lib/sdl_ttf/include" }

    -- Diretório onde as bibliotecas a serem linkadas se encontram.
    -- OBSERVAÇÃO: deve-se atualizar o diretório da pasta lib da SDL aqui.
    -- Costuma não ser necessário no Linux. Remova se causar problemas.
    libdirs { "C:/SDL2/SDL-2.30.1/lib" }

    -- Aqui são linkados as diversas bibliotecas necessárias.
    links
    {
        "SDL2",
        "SDL2main",
        "SDL2_image",
        "SDL2_mixer",
        "SDL2_ttf"
    }

    -- Filtro para configurações específicas do sistema linux (não é necessário para Windows).
    filter "system:linux"
        pic "On"

    -- Filtro para configurações no modo debug.
    filter "configurations:debug"
        buildoptions { "-Wall", "-Wextra", "-O0" }
        defines { "DEBUG" } -- Definições de flags para uso no modo debug 'equivalente a usar -D'.
        symbols "On" -- 'equivalente a usar -g'
        runtime "Debug"

    -- Filtro para configurações no modo release.
    filter "configurations:release"
        symbols "Off" -- Retira -g
        optimize "On"  -- 'equivalente a usar -O2'
        runtime "Release"
