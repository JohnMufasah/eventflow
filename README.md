# EventFlow

COS 214 Practical 3 — a live event coordination engine using the Observer
and Composite design patterns.

## Team
- Musa
- Manasse
- Reneilwe

## Event Concept
*(Fill in once Task 1.1 is locked — event name, theme, what happens there.)*

## Architecture Overview
*(Fill in once Task 1.3 is locked — brief summary of the Composite tree
shape and the Observer notification structure. Link to the full class
diagram in docs/ once it exists.)*

## Building

```
make
```

Produces an executable named `eventflow`.

```
make clean
```

Removes build artifacts.

## Running

```
./eventflow
```

## Documentation

This project uses Doxygen for code documentation.

```
doxygen Doxyfile
```

Generates browsable HTML documentation in `docs/html/` (open
`docs/html/index.html` in a browser).

## Design Decisions

*(Fill in: push vs pull for Observer, who owns observer references, who
owns Composite children, etc. — see design rationale in the submitted PDF
for the full explanation.)*
