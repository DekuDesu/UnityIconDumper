## Unity Icon Dumper
Dumps the unity assets paths for all files with the provided extension located within `catalog.json` for Unity Streaming Assets catalogs.

### Usage
Ran from command line  

```
IconDumper.exe <catalog_path> <extension> [| output]
```  

```powershell
.\IconDumper.exe path_to_catalog.json > path_to_output_file.txt
```

Example (no output file)
```powershell
.\IconDumper.exe catalog.json png
Assets/RoR2/Base/Characters/Merc/texMercIcon.png
Found 1 icons
```
Example (outputting to file)  

`powershell.exe`
```powershell
.\IconDumper.exe catalog.json png > output.txt
```  

`output.txt`
```txt
Assets/RoR2/Base/Characters/Merc/texMercIcon.png
Found 1 icons
```