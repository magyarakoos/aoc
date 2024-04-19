using Intervals
f = open("input", "r")
start = Vector{Interval{Closed, Closed}}()
m = match(r"\S+(.*)", readline(f))
