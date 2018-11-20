FOR %%A IN (2015-2016,2017,2018) DO (
python pg.py %%A.json
"C:\Program Files (x86)\MSBuild\14.0\Bin\msbuild.exe" "../TVS_Ventilation %%A.sln" /property:Configuration=Release /property:Condition=x64
"C:\Program Files (x86)\MSBuild\14.0\Bin\msbuild.exe" "../TVS_Ventilation %%A.sln" /property:Configuration=Release /property:Condition=Win32
)

FOR %%A IN (2013-2014,2010-2012) DO (
python pg.py %%A.json
"C:\Program Files (x86)\MSBuild\12.0\Bin\msbuild.exe" "../TVS_Ventilation %%A.sln" /property:Configuration=Release /property:Condition=x64
"C:\Program Files (x86)\MSBuild\12.0\Bin\msbuild.exe" "../TVS_Ventilation %%A.sln" /property:Configuration=Release /property:Condition=Win32
)

FOR %%A IN (2019) DO (
python pg.py %%A.json
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\msbuild.exe" "../TVS_Ventilation %%A.sln" /property:Configuration=Release /property:Condition=x64
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\msbuild.exe" "../TVS_Ventilation %%A.sln" /property:Configuration=Release /property:Condition=Win32
)

"C:\Program Files (x86)\Inno Setup 5\iscc.exe" "../TVS_install Tools+Vent2015-2019.iss"
python pg.py 2015-2016.json