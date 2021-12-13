import msalign as m

# base cases
assert m.align(query="", subject="") == ""
assert m.align(query="MMM", subject="") == ""
assert m.align(query="", subject="MMM") == "---"

assert m.align(query="M", subject="M") == "M"
assert m.align(query="M", subject="MMM") == "--M"
assert m.align(query="WM", subject="WMMM") == "WM--"

assert m.align(query="WMAM", subject="WMMM") == "WMAM"

assert m.align("ATTTTY", "ATTTT-IT") == "ATTTT--Y"
assert m.align("ATTTTY", "ATTTT--IT") == "ATTTT---Y"
