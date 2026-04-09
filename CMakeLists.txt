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
    src/domain/IncidentBookmark.cpp
    src/domain/Mission.cpp
    src/domain/OperatorNote.cpp
    src/domain/OverlayProfile.cpp
    src/domain/PlatformHealth.cpp
    src/domain/Route.cpp
    src/domain/Scenario.cpp
    src/domain/SessionSummary.cpp
    src/domain/TrackState.cpp
    src/domain/ValidationIssue.cpp
    src/domain/Zone.cpp
    src/services/AlertRuleEngine.cpp
    src/services/BookmarkRepository.cpp
    src/services/EventJournal.cpp
    src/services/MissionSessionRepository.cpp
    src/services/RecentSessionStore.cpp
    src/services/ReportExporter.cpp
    src/services/RulePackRepository.cpp
    src/services/ScenarioRepository.cpp
    src/services/ScenarioValidator.cpp
    src/services/WorkspaceRepository.cpp
    src/simulation/SimulationEngine.cpp
    src/simulation/ThreatModel.cpp
    src/simulation/TimelineScheduler.cpp
    src/ui/MainWindow.cpp
    src/ui/dialogs/AlertRulesDialog.cpp
    src/ui/dialogs/ExportDialog.cpp
    src/ui/dialogs/ScenarioEditorDialog.cpp
    src/ui/dialogs/SessionManagerDialog.cpp
    src/ui/dialogs/SettingsDialog.cpp
    src/ui/dialogs/WorkspaceLayoutDialog.cpp
    src/ui/models/BookmarkTableModel.cpp
    src/ui/models/TrackTableModel.cpp
    src/ui/widgets/AlertsWidget.cpp
    src/ui/widgets/BookmarkWidget.cpp
    src/ui/widgets/EventLogWidget.cpp
    src/ui/widgets/HealthPanelWidget.cpp
    src/ui/widgets/InspectorWidget.cpp
    src/ui/widgets/LayerControlWidget.cpp
    src/ui/widgets/MapCanvas.cpp
    src/ui/widgets/NotesWidget.cpp
    src/ui/widgets/PlannerWidget.cpp
    src/ui/widgets/ScenarioBrowserWidget.cpp
    src/ui/widgets/SummaryStripWidget.cpp
    src/ui/widgets/TimelineWidget.cpp
    src/ui/widgets/TrackTableWidget.cpp
    src/ui/widgets/ValidationPanelWidget.cpp
)

target_include_directories(mission_control_studio_ultimate PRIVATE src)
target_link_libraries(mission_control_studio_ultimate PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
