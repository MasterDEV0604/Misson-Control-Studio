# Mission Control Studio Ultimate

Mission Control Studio Ultimate is a **Qt 6 / C++17 autonomy operations workstation** for mission planning, live supervision, replay analysis, alert triage, operator note taking, and debrief export.

This repository is designed as a **public flagship portfolio project** that feels like a real internal engineering tool. The codebase intentionally separates the product into application, domain, service, simulation, and UI layers, and it includes scenario packages, rule packs, session templates, exported artifacts, architecture notes, and CI scaffolding.

## Product vision

A field robotics or autonomy team needs a desktop application that can:
- open scenario packages and validate them before execution
- supervise multiple tracks on a shared operational map
- highlight incidents such as route conflicts, degraded confidence, or rule violations
- let operators add notes and bookmarks during playback
- restore the previous workspace layout and recent session state
- export a structured post-run debrief package

This repository focuses on those workflows.

## What makes this repo feel closer to a real product

- **multi-dock workstation UI** with map, planner, alerts, notes, timeline, inspector, validation, health, and session panels
- **scenario packages** with fictional but realistic mission metadata
- **rule-pack loading** for operational alert profiles
- **session persistence** for workspace layout and operator preferences
- **bookmark and note capture** for replay/debrief workflows
- **debrief export** with markdown summaries and incident tables
- **docs, ADRs, scripts, configs, artifacts, and roadmap** instead of only source files
- **CI scaffolding and tests directory** so the repository reads like an engineered application

## Main workflows

### 1) Pre-mission validation
1. Open a scenario package from `assets/scenarios/`.
2. Review issues in the validation panel.
3. Load an alert rule pack from `assets/rulepacks/`.
4. Confirm overlay defaults and route safety hints.

### 2) Live supervision and playback
1. Start playback or step through the mission timeline.
2. Monitor tracks, threat rings, health state, and route conflict warnings.
3. Add operator notes and incident bookmarks.
4. Filter visible tracks and toggle map overlays.

### 3) Debrief and export
1. Open the bookmark/history panel.
2. Review major mission events and operator comments.
3. Export a debrief package to `artifacts/example_reports/`.
4. Use the markdown report during post-run review.

## Repository layout

```text
src/
  app/                    application orchestration
  domain/                 scenarios, tracks, notes, zones, bookmarks, health
  services/               validation, persistence, rules, export, journaling
  simulation/             timeline and playback engine
  ui/
    dialogs/              settings, scenario editor, session manager, rules
    models/               Qt table/list models
    widgets/              operator workstation panels
assets/
  scenarios/              fictional mission packages
  rulepacks/              alert and policy profiles
  session_templates/      canned operator workspace defaults
  workspaces/             saved window/session snapshots
  styles/                 QSS themes
configs/                  repo-level defaults
scripts/                  artifact and screenshot helper scripts
artifacts/
  example_reports/        exported debrief examples
  screens/                placeholder screenshot notes
.github/workflows/        CI scaffolding
docs/                     architecture, workflows, screenshots, ADRs
```

## Build

### Requirements
- Qt 6.5+
- CMake 3.20+
- C++17 compiler

### Configure
```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH=/path/to/Qt/6.x
cmake --build build -j
```

### Run
```bash
./build/mission_control_studio_ultimate
```

## Screenshot plan

See `docs/screenshots.md` and `docs/mockups/` for the recommended GitHub presentation shots.

## Public portfolio note

All missions, routes, entities, map names, and events are fictional and sanitized. The portfolio value is the **engineering shape** of the application: operator workflow, layered design, state handling, validation, persistence, replay, debrief export, and multi-panel UI composition.
