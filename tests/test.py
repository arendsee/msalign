import msalign as m

# base cases
assert m.align(query="", subject="") == ""
assert m.align(query="MMM", subject="") == ""
assert m.align(query="", subject="MMM") == "---"

# upper and lower cases
assert m.align(query="GANDALF", subject="GANANDORF") == "---"

assert m.align(query="M", subject="M") == "M"
assert m.align(query="M", subject="MMM") == "--M"
assert m.align(query="WM", subject="WMMM") == "WM--"

assert m.align(query="WMAM", subject="WMMM") == "WMAM"
