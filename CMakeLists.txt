cmake_minimum_required(VERSION 3.20)
project(mission_control_studio_ultimate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(mission_control_studio_ultimate
    src/main.cpp
    src/app/ApplicationController.cpp
    src/app/WorkspaceState.cpp
    src/domain/Alert.cpp
    src/domain/Mission.cpp
    src/domain/OverlayProfile.cpp
    src/domain/Route.cpp
    src/domain/Scenario.cpp
    src/domain/TrackState.cpp
    src/services/AlertRuleEngine.cpp
    src/services/EventJournal.cpp
    src/services/ReportExporter.cpp
    src/services/ScenarioRepository.cpp
    src/services/ScenarioValidator.cpp
    src/services/WorkspaceRepository.cpp
    src/simulation/SimulationEngine.cpp
    src/simulation/ThreatModel.cpp
    src/simulation/TimelineScheduler.cpp
    src/ui/MainWindow.cpp
    src/ui/dialogs/ExportDialog.cpp
    src/ui/dialogs/ScenarioEditorDialog.cpp
    src/ui/dialogs/SettingsDialog.cpp
    src/ui/models/TrackTableModel.cpp
    src/ui/widgets/AlertsWidget.cpp
    src/ui/widgets/EventLogWidget.cpp
    src/ui/widgets/HealthPanelWidget.cpp
    src/ui/widgets/InspectorWidget.cpp
    src/ui/widgets/LayerControlWidget.cpp
    src/ui/widgets/MapCanvas.cpp
    src/ui/widgets/PlannerWidget.cpp
    src/ui/widgets/ScenarioBrowserWidget.cpp
    src/ui/widgets/TimelineWidget.cpp
    src/ui/widgets/TrackTableWidget.cpp
)

target_include_directories(mission_control_studio_ultimate PRIVATE src)
target_link_libraries(mission_control_studio_ultimate PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
