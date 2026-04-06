# Mission Control Studio Ultimate

Mission Control Studio Ultimate is a **Qt 6 / C++17 desktop operations workstation** for scenario planning, mission playback, live track supervision, overlay control, alert review, and operator debrief export.

This repository is intentionally built as a **flagship public portfolio project** that demonstrates the architecture, UX structure, and product workflow of a serious internal engineering tool without exposing restricted work.

## Why this repo is stronger than a demo

It is organized like a real product:

- multi-dock operator workstation
- application / domain / services / simulation / ui layers
- scenario repository with validation and revision metadata
- alert rule engine and health summary generation
- route editing and timeline playback workflow
- workspace persistence and recent-session restore
- debrief export and artifacts directory
- architecture docs, ADRs, screenshots guide, roadmap, and test notes

## Product concept

An operator supervises multiple autonomous or semi-autonomous platforms inside a mapped mission area. The workstation supports:

- opening and validating scenario packages
- reviewing mission objectives and platform status
- editing routes and waypoint timing
- switching overlay layers and filtering tracks
- replaying historical mission timelines
- surfacing rule-based alerts and operator notes
- exporting a post-run debrief package
- restoring workstation layout and user preferences

## Repository layout

```text
src/
  app/              application orchestration and workspace state
  domain/           mission, track, route, alert, overlay, scenario models
  services/         repositories, validation, export, journaling, rules
  simulation/       scheduler, playback engine, threat heuristics
  ui/
    dialogs/        settings, scenario editor, export dialogs
    models/         qt models for tables and lists
    widgets/        map, planner, timeline, browser, inspector, alerts, health
assets/
  scenarios/        fictional sample scenarios
  styles/           qss themes
  icons/            simple vector placeholders
  workspaces/       saved workspace examples
docs/
  architecture.md
  product_requirements.md
  operator_walkthrough.md
  roadmap.md
  screenshots.md
  adr/
artifacts/
  example_reports/
tests/
  notes.md
```

## Build

### Requirements
- Qt 6.5+
- CMake 3.20+
- A C++17 compiler

### Configure
```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH=/path/to/Qt/6.x
cmake --build build -j
```

### Run
```bash
./build/mission_control_studio_ultimate
```

## High-value operator workflows

### Open and validate a scenario
1. Start the application.
2. Open a scenario from `assets/scenarios`.
3. Review validation results in the status bar and event log.
4. Inspect mission summary, overlays, and track table.

### Plan and review a route change
1. Select a track in the track table.
2. Edit route points in the planner.
3. Save the scenario revision from the Scenario Editor dialog.
4. Review new event entries and threat warnings.

### Run playback and export debrief
1. Start playback from the timeline dock.
2. Scrub, pause, speed up, and inspect key alerts.
3. Export a markdown debrief package to `artifacts/`.

## What to capture for GitHub screenshots
See `docs/screenshots.md`.

## Public portfolio note
All missions, assets, track names, and scenario details in this repo are fictional and sanitized. The value of this project is the **software engineering shape**: UI composition, modular structure, state handling, validation, simulation plumbing, and product-oriented workflows.
