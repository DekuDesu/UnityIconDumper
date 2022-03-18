## Unity Icon Dumper
Dumps the unity assets paths for all `.png` files located within `catalog.json` for Unity Games.

### Usage
Ran from command line
```powershell
.\IconDumper.exe "path_to_catalog.json" > "path_to_output_file.txt"
```

Example (no output file)
```powershell
.\IconDumper.exe "catalog.json"
Assets/RoR2/Base/Characters/Merc/texMercIcon.png
Found 1 icons
```
Example (outputting to file)  

`powershell.exe`
```powershell
.\IconDumper.exe "catalog.json" > output.txt
```  

`output.txt`
```txt
Assets/RoR2/Base/Characters/Merc/texMercIcon.png
Found 1 icons
```