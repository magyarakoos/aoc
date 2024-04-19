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
    diff = Vector{Int}()
    while true
        l = readline(f)
        if l == "" break end
        l = map(x -> parse(Int, x), split(l))
        push!(source, Interval{Closed, Open}(l[2], l[2] + l[3]))
        push!(diff, l[1] - l[2])
    end

    push!(source, Interval{Closed, Open}(0, minimum(m)))
    for _ in 1:2 push!(diff, 0) end

    curr = Vector{Interval{Int, Closed, Open}}()
    for intv in start
        for i in eachindex(source)
            sect = intv ∩ source[i]
            # println((intv, source[i]))
            if !isempty(sect)
                push!(curr, Interval{Closed, Open}(
                    first(intv) + diff[i], 
                    last(intv) + diff[i]
                ))
                println((intv, curr[end]))
            end
        end
    end
    global start = copy(curr)
end