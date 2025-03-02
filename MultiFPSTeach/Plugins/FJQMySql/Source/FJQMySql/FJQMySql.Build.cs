// Some copyright should be here...

using UnrealBuildTool;
using System.IO;

public class FJQMySql : ModuleRules
{
	private string LibrariesPath
	{
		get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/")); }
	}

	public string BinariesPath
	{
		get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../Binaries/Win64/")); }
	}
	
	public FJQMySql(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateIncludePaths.AddRange(new string[]
		{
			"FJQMySQL/Private"

		});


		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		bEnableUndefinedIdentifierWarnings = false;
		bEnableExceptions = true;

		PublicDefinitions.Add("NTDDI_WIN7SP1");

		PublicDependencyModuleNames.AddRange(new[] 
		{   
			"Core", 
			"CoreUObject", 
			"Engine", 
			"RHI",
			"RenderCore", 
			"InputCore" , 
			"Projects" 
		});
		PrivateDependencyModuleNames.AddRange(new[]
		{
			"XmlParser", 
			"Core", 
			"Engine"
		});

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicDelayLoadDLLs.Add(Path.Combine(LibrariesPath, "FileBrowser.dll"));
			PublicDelayLoadDLLs.Add(Path.Combine(LibrariesPath, "MySQLLibrary.dll"));
            
			PublicDelayLoadDLLs.Add(Path.Combine(BinariesPath, "mysqlcppconn-9-vs14.dll"));
			PublicDelayLoadDLLs.Add(Path.Combine(BinariesPath, "libcrypto-1_1-x64.dll"));
			PublicDelayLoadDLLs.Add(Path.Combine(BinariesPath, "libssl-1_1-x64.dll"));
     
			RuntimeDependencies.Add(Path.Combine(LibrariesPath, "FileBrowser.dll"));
			RuntimeDependencies.Add(Path.Combine(LibrariesPath, "MySQLLibrary.dll"));
            
			RuntimeDependencies.Add(Path.Combine(BinariesPath, "mysqlcppconn-9-vs14.dll"));
			RuntimeDependencies.Add(Path.Combine(BinariesPath, "libcrypto-1_1-x64.dll"));
			RuntimeDependencies.Add(Path.Combine(BinariesPath, "libssl-1_1-x64.dll"));
		}
	}
}
