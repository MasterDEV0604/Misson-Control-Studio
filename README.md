# Mission Control Studio Ultimate

Mission Control Studio Ultimate is a **Qt 6 / C++17 desktop workstation for mission planning, live supervision, replay analysis, and post-run debriefing**.

The application is designed for teams building or evaluating autonomous systems that need a single operator console for scenario review, timeline playback, track supervision, incident triage, and session reporting.

## Highlights

- **Multi-dock operator workspace** with map, planner, timeline, alerts, validation, notes, inspector, and health panels
- **Scenario package workflow** for loading mission definitions, routes, overlays, and constraints
- **Rule-pack driven alerting** for route conflict, degraded confidence, and operational policy checks
- **Replay and investigation tools** including timeline scrubbing, bookmarks, and operator notes
- **Workspace persistence** for restoring layout, recent sessions, and operator preferences
- **Debrief export** for generating mission summaries and incident reports
- **Layered application structure** across UI, application control, domain model, services, and simulation engine

## Primary use cases

Mission Control Studio Ultimate is intended for workflows such as:

- pre-run scenario validation before a mission or simulation session
- live supervision of multiple platforms on a shared 2D operational map
- replay review after a test run or exercise
- incident documentation and operator note capture
- debrief generation for engineering, test, or training teams

## Feature overview

### Mission preparation
- open scenario packages from disk
- validate route definitions, entity metadata, and mission settings
- load alert rule packs for the active mission profile
- configure overlays and workspace layout before execution

### Supervision and playback
- monitor active tracks on a live map canvas
- inspect entity and track state in side panels
- review alerts, health status, and validation issues during runtime
- scrub, pause, resume, and step through the timeline
- add bookmarks and operator notes during playback or review

### Debrief and reporting
- collect timeline events and notable incidents
- review session summary information
- export markdown-style debrief artifacts for post-run analysis

## Architecture

The codebase is organized around clear engineering boundaries:

```text
src/
  app/                    Application orchestration and session-level control
  domain/                 Missions, tracks, routes, overlays, alerts, notes, health
  services/               Validation, persistence, journaling, export, repository logic
  simulation/             Timeline scheduling and playback engine
  ui/
    dialogs/              Settings, scenario editing, rule-pack, and session dialogs
    models/               Qt item models
    widgets/              Dockable workstation panels and map components
assets/
  scenarios/              Example mission packages
  rulepacks/              Alert policy definitions
  session_templates/      Saved workspace/session defaults
  workspaces/             Session state snapshots
  styles/                 UI themes
configs/                  Application defaults
artifacts/                Example exported reports
scripts/                  Utility scripts
```

## Build

### Requirements
- Qt 6.5 or newer
- CMake 3.20 or newer
- C++17 compiler

### Configure and build
```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH=/path/to/Qt/6.x
cmake --build build -j
```

### Run
```bash
./build/mission_control_studio_ultimate
```

## Example workflow

1. Launch the application and open a scenario from `assets/scenarios/`.
2. Review validation results and load an alert profile from `assets/rulepacks/`.
3. Start playback and monitor tracks, overlays, and system health.
4. Add bookmarks or notes for important moments.
5. Export a debrief package for review after the session.

## Outputs

Mission Control Studio Ultimate can generate or maintain outputs such as:

- session summaries
- incident and bookmark lists
- operator notes
- exported debrief markdown reports
- saved workspace layout and recent-session state

## Documentation

Additional design notes are available in:

- `docs/architecture.md`
- `docs/workflows.md`
- `docs/screenshots.md`
- `docs/adr/`

## Roadmap

Planned areas of expansion include:

- richer map editing and waypoint authoring
- advanced filtering and search across tracks and incidents
- comparative replay views for side-by-side run analysis
- charting panels for confidence, health, and route quality
- external data adapters for simulation and analytics pipelines

## Notes

All bundled scenarios and mission assets are fictional and intended for software demonstration, validation, and user-interface development.
