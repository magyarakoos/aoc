using Intervals
f = open("input", "r")
start = Vector{Interval{Int, Closed, Open}}()
m = map(x -> parse(Int, x), split(match(r"\S+(.*)", readline(f))[1]))
for i in 2:2:length(m)
    push!(start, Interval{Closed, Open}(m[i - 1], m[i - 1] + m[i]))
end
readline(f)
while !eof(f)
    readline(f)
    source = Vector{Interval{Int, Closed, Open}}()
    dest = copy(source)
    while true
        l = readline(f)
        if l == "" break end
        l = map(x -> parseInt, xsplit(l)
        push!(dest, Interval{Closed, Open}(l[1], l[1] + l[3]))
        push!(source, Interval{Closed, Open}(l[2], l[2] + l[3]))
    end
end