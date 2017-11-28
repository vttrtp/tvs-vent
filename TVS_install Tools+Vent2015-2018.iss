; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "TVS_Vent_Tools_2015-2018(x64,x32)_version(3.2)"
#define MyAppVersion "3.2"
#define MyAppPublisher "Vitaut Tryputsin"
#define MyAppURL "http://www.tvs-vent.by/"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)

AppId={{94530D46-364B-4468-8F35-4D37B8AE512E}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={commonappdata}\Autodesk\ApplicationPlugins\TVS.bundle\
DisableDirPage=yes
DefaultGroupName={#MyAppName}
DisableProgramGroupPage=yes
OutputDir={#SourcePath}\Installer\Versions
OutputBaseFilename={#MyAppName}
Compression=lzma
SolidCompression=yes

[Languages]
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"

[Files]
Source: "{#SourcePath}\Installer\PackageContents.xml"; DestDir: "{app}\";  Flags: ignoreversion  
Source: "{#SourcePath}\Installer\Resources\*"; DestDir: "{app}\Contents\Resources";  Flags: ignoreversion  recursesubdirs

;2015-2016
;x64
Source: "{#SourcePath}\x64\Release\2015-2016\TVSTVS_Ventilation_ARX.arx"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\2015-2016\win64"; Flags: ignoreversion
Source: "{#SourcePath}\x64\Release\2015-2016\TVSTVS_Ventilation_DBX.dbx"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\2015-2016\win64"; Flags: ignoreversion
;x32
Source: "{#SourcePath}\Win32\Release\2015-2016\TVSTVS_Ventilation_ARX.arx"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\2015-2016\win32"; Flags: ignoreversion
Source: "{#SourcePath}\Win32\Release\2015-2016\TVSTVS_Ventilation_DBX.dbx"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\2015-2016\win32"; Flags: ignoreversion
;/////

;2017
;x64
Source: "{#SourcePath}\x64\Release\2017\TVSTVS_Ventilation_ARX.arx"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\2017\win64"; Flags: ignoreversion
Source: "{#SourcePath}\x64\Release\2017\TVSTVS_Ventilation_DBX.dbx"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\2017\win64"; Flags: ignoreversion
;x32
Source: "{#SourcePath}\Win32\Release\2017\TVSTVS_Ventilation_ARX.arx"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\2017\win32"; Flags: ignoreversion
Source: "{#SourcePath}\Win32\Release\2017\TVSTVS_Ventilation_DBX.dbx"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\2017\win32"; Flags: ignoreversion
;/////


;2018
;x64
Source: "{#SourcePath}\x64\Release\2018\TVSTVS_Ventilation_ARX.arx"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\2018\win64"; Flags: ignoreversion
Source: "{#SourcePath}\x64\Release\2018\TVSTVS_Ventilation_DBX.dbx"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\2018\win64"; Flags: ignoreversion
;x32
Source: "{#SourcePath}\Win32\Release\2018\TVSTVS_Ventilation_ARX.arx"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\2018\win32"; Flags: ignoreversion
Source: "{#SourcePath}\Win32\Release\2018\TVSTVS_Ventilation_DBX.dbx"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\2018\win32"; Flags: ignoreversion
;/////

Source: "{#SourcePath}\Installer\TVS_TOOLS\*"; DestDir: "{app}\Contents\TVS_TOOLS\Resources"; Components: TVS_TOOLS; Flags: ignoreversion
Source: "{#SourcePath}\Installer\TVS_VENT\*"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\Resources"; Flags: ignoreversion recursesubdirs
;Source: "{#SourcePath}\..\codegenerator\Release\Activator TVS-Vent.exe"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\Activator"; Flags: ignoreversion 
;Source: "{#SourcePath}\Installer\dlls\x32\*"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\Activator"; Flags: ignoreversion recursesubdirs 
;Source: "{#SourcePath}\Installer\dlls\x64\*"; Components: TVS_VENT; DestDir: "{app}\Contents\TVS_VENT\2015-2016\win64"; Flags: ignoreversion recursesubdirs 


; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
;Name: "{group}\������������ TVS-Vent"; Filename: "{app}\Contents\TVS_VENT\Activator\Activator TVS-Vent.exe"

[Types]
Name: "full"; Description: "������ ���������"
Name: "custom"; Description: "���������� ���������"; Flags: iscustom
[Components]
Name: "TVS_TOOLS"; Description: "TVS_TOOLS: ��������� ��� ���������� ������������"; Types: full 
Name: "TVS_VENT"; Description: "TVS_VENT: ��������� ��� ���������� ������������"; Types: full 

[Code]

[Registry]
Root: HKCU; Subkey: "Software\{#MyAppPublisher}"; Flags: uninsdeletekeyifempty
Root: HKCU; Subkey: "Software\{#MyAppPublisher}\TVS_Vent\"; Flags: uninsdeletekeyifempty
Root: HKCU; Subkey: "Software\{#MyAppPublisher}\TVS_Vent\{#MyAppVersion}"; ValueType: string; ValueName: "Path"; ValueData: "{app}"
Root: HKCU; Subkey: "Software\{#MyAppPublisher}\TVS_Vent\{#MyAppVersion}"; ValueType: string; ValueName: "CurrentVersion"; ValueData: "{#MyAppVersion}"

[Run]
;Filename: "{app}\Contents\TVS_VENT\Activator\Activator TVS-Vent.exe";