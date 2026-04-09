# Architecture

Mission Control Studio Ultimate is organized into five layers:

## 1. Application layer
Coordinates startup, scenario loading, workspace restore, and debrief export.

## 2. Domain layer
Contains mission entities such as tracks, routes, zones, operator notes, and incident bookmarks.

## 3. Services layer
Implements repositories, validation, rule-pack loading, recent-session storage, export, and journaling.

## 4. Simulation layer
Provides timeline stepping, playback rate control, and simple operational-state heuristics.

## 5. UI layer
Owns the workstation composition: map canvas, planner, inspector, alerts, notes, validation, health, timeline, and summary strip.

## Product-oriented subsystems
- **Scenario package flow**: repository -> validator -> controller -> UI
- **Rule-pack flow**: rule-pack repository -> alert engine -> alerts widget
- **Session flow**: workspace/session repositories -> recent-session store -> dialogs/widgets
- **Debrief flow**: notes/bookmarks/events -> report exporter -> markdown artifacts
