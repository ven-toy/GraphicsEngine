-- /Build-Vendor.lua



group "Core"
    include "Core/Build-Core.lua"
group ""

include "App/Build-App.lua"

-- Define the path to the Modules directory
local modulesPath = "Modules"

-- Find all Build.lua files within the Modules directory and its subdirectories
local buildFiles = os.matchfiles(modulesPath .. "/**/Build.lua")

-- Iterate over each found Build.lua file
for _, buildFile in ipairs(buildFiles) do
    -- Extract the module directory from the build file path
    local moduleDir = path.getdirectory(buildFile)

    -- Extract the module name from the directory path
    local moduleName = path.getname(moduleDir)

    -- Group the module under "Modules"
    group "Modules"
        -- Include the Build.lua script
        include(buildFile)
    group ""
end
