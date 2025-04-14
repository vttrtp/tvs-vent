# TVS_VENT

**TVS_VENT** is a ObjectARX-based AutoCAD plugin designed for drafting and managing ventilation systems. It enhances AutoCAD's core functionality with custom entities and intuitive commands tailored specifically for HVAC design.

**TVS_TOOLS** plugin for parsing 1D floor plans and generating axonometric schemes using AutoCAD primitives + several oher commands.

**Note:** This program features a Russian interface.

---

## 🚀 Features

- **Custom Ventilation Components**  
  Create and manage ducts, tees, elbows, and other ventilation elements using specialized entities.

- **Interactive Editing**  
  Modify dimensions, types, and attributes of ventilation ducts with grips, dialogs, and contextual commands.

- **Axonometric Diagram Generation**  
  Automatically generate axonometric diagrams from floor plans using the companion `TVS_TOOLS` plugin.

- **Airflow Calculator**  
  Built-in calculator to determine:
  - Air velocity
  - Airflow rate
  - Pressure loss

- **Dimension Callouts & Labels**  
  Automatically generate clear callouts and annotations for ducts and equipment.

- **Specification Export**  
  Generate complete equipment and duct specifications, with optional export to Excel.

- **1D/2D Display Switching**  
  Toggle between simplified 1D or full 2D visual representations of the duct system.

- **Duct Masking**  
  Hide ducts and objects below others by controlling their draw order for clean visualization.

- **Block Attribute Integration**  
  Add and manage attributes for custom equipment blocks—fully integrated with specifications and callouts.

- **Block Manager**  
  Modify attributes for selected blocks with a centralized interface.

---

## 📦 System Requirements

- **AutoCAD** 2015-2024 or compatible version (must support ObjectARX)
- **Windows** 10/11

---

## 🔧 Installation

1. Download the appropriate version of the plugin from the [Downloads](#📥-downloads) section above.
2. Run Installer
3. Open Autocad with administrative permissions once

---

## 🔨 Building

To build the project, follow these steps:

1. **Download ObjectARX**  
   Download the ObjectARX SDK for AutoCAD 2024 from the [Autodesk Developer Network (ADN)](https://www.autodesk.com/developer-network/platform-technologies/autocad/objectarx-download).  
   Place the downloaded files in the `ThirdParty` folder under `ObjextARX2024`.

2. **Install Inno Setup**  
   Download and install the Inno Setup installer program from [Inno Setup Downloads](https://jrsoftware.org/isdl.php).

3. **Run the Build Script**  
   Navigate to the `project generator` folder and run `regenerate.bat`. This script will:
   - Generate project files.
   - Build the solution for the specified AutoCAD versions.
   - Create the installer using Inno Setup.

4. **Locate the Output**  
   After running the script, the resulting `.exe` installer file will be located in the `Installer\Versions` folder.

---

## 📥 Downloads

### Available Versions
- [TVS_Vent_Tools_2015-2018 (x64, x32) version 3.2 (EXE)](https://raw.githubusercontent.com/vttrtp/tvs-vent/master/Installer/Versions/TVS_Vent_Tools_2015-2018(x64,x32)_version(3.2).exe)
- [TVS_Vent_Tools_2015-2019 (x64, x32) version 3.3 (EXE)](https://raw.githubusercontent.com/vttrtp/tvs-vent/master/Installer/Versions/TVS_Vent_Tools_2015-2019(x64,x32)_version(3.3).exe)
- [TVS_Vent_Tools_2015-2019 (x64, x32) version 3.3.1 (EXE)](https://raw.githubusercontent.com/vttrtp/tvs-vent/master/Installer/Versions/TVS_Vent_Tools_2015-2019(x64,x32)_version(3.3.1).exe)
- [TVS_Vent_Tools_2015-2020 (x64, x32) version 3.3.1 (EXE)](https://raw.githubusercontent.com/vttrtp/tvs-vent/master/Installer/Versions/TVS_Vent_Tools_2015-2020(x64,x32)_version(3.3.1).exe)
- [TVS_Vent_Tools_2021-2022 (x64, x32) version 3.3.1 (EXE)](https://raw.githubusercontent.com/vttrtp/tvs-vent/master/Installer/Versions/TVS_Vent_Tools_2021-2022(x64,x32)_version(3.3.1).exe)
- [TVS_Vent_Tools_2024 (x64, x32) version 3.3.1 (EXE)](https://raw.githubusercontent.com/vttrtp/tvs-vent/master/Installer/Versions/TVS_Vent_Tools_2024(x64,x32)_version(3.3.1).exe)

---

## 🧪 Development

TVS_VENT is developed in C++ using the **ObjectARX SDK**. The project extends AutoCAD with:
- Custom entities
- Event handling (grips, commands)
- Dialog UI integration

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).