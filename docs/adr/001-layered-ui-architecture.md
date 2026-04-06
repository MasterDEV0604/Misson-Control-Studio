# ADR 001: Layered UI Architecture

## Decision
Keep scenario management and simulation state in an application controller rather than inside the main window.

## Why
This keeps the Qt widget tree slimmer, makes future tests easier, and gives the repo a more realistic separation of concerns.
