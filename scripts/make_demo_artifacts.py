from pathlib import Path
root = Path(__file__).resolve().parents[1]
out = root / 'artifacts' / 'example_reports' / 'generated_demo.md'
out.write_text('# Generated demo artifact

This placeholder can be replaced by a real exported report after a local Qt run.
', encoding='utf-8')
print(f'wrote {out}')
