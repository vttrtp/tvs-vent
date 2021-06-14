@REM FOR %%A IN (2015-2016,2017,2018) DO (
@REM python pg.py %%A.json
@REM "C:\Program Files (x86)\MSBuild\14.0\Bin\msbuild.exe" "../TVS_Ventilation %%A.sln" /property:Configuration=Release /property:Platform=x64
@REM "C:\Program Files (x86)\MSBuild\14.0\Bin\msbuild.exe" "../TVS_Ventilation %%A.sln" /property:Configuration=Release /property:Platform=Win32
@REM )

@REM FOR %%A IN (2019) DO (
@REM python pg.py %%A.json
@REM "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\msbuild.exe" "../TVS_Ventilation %%A.sln" /property:Configuration=Release /property:Platform=x64
@REM "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\msbuild.exe" "../TVS_Ventilation %%A.sln" /property:Configuration=Release /property:Platform=Win32
@REM )

@REM FOR %%A IN (2020) DO (
@REM python pg.py %%A.json
@REM "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\msbuild.exe" "../TVS_Ventilation %%A.sln" /property:Configuration=Release /property:Platform=x64
@REM )

@REM FOR %%A IN (2021 2022) DO (
@REM python pg.py %%A.json
@REM "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\msbuild.exe" "../TVS_Ventilation %%A.sln" /property:Configuration=Release /property:Platform=x64
@REM )

"C:\Program Files (x86)\Inno Setup 6\iscc.exe" "../TVS_install Tools+Vent2021-2022.iss"
python pg.py 2015-2016.json
