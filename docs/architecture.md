# Architecture

Mission Control Studio Ultimate uses a layered structure:

- **domain**: plain mission objects like Scenario, Mission, Route, TrackState, Alert
- **services**: scenario parsing, validation, report generation, alert rule evaluation, persistence
- **simulation**: timeline progression and rule-driven state evolution for sample scenarios
- **app**: orchestration layer that coordinates scenario loading, active workspace state, engine updates, and journaling
- **ui**: Qt widgets, table models, dialogs, and docking layout

## Design goals

1. Keep domain structures portable and easy to unit test.
2. Keep Qt-heavy code inside the ui layer where possible.
3. Expose clear extension points for new overlays, rules, exporters, and scenario fields.
4. Favor believable operator workflows over novelty demos.
