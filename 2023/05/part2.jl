using Intervals

f = open("input", "r")
start = Vector{Interval{Int, Closed, Open}}()
m = map(x -> parse(Int, x), split(match(r"\S+(.*)", readline(f))[1]))
for i in 2:2:length(m)
    push!(start, Interval{Closed, Open}(m[i - 1], m[i - 1] + m[i]))
end

function →(intvs)
    intvs2 = []
    for intv in intvs
        i = 1
        while i <= length(intvs2)
            if !isempty(intvs2[i] ∩ intv)
                intvs2[i] = (
                    min(intvs2[i][1], intv[1]), 
                    max(intvs2[i][2], intv[2])
                )
                break
            end
            i += 1
        end
        if i > length(intvs2)
            push!(intvs2, intv)
        end
    end
    if (length(intvs) == length(intvs2))
        return intvs2
    end
    →(intvs2)
end

readline(f)
while !eof(f)
    label = readline(f)[1]
    if label == 'h' break end
    source = Vector{Interval{Int, Closed, Open}}()
    diff = Vector{Int}()
    while true
        l = readline(f)
        if l == "" break end
        l = map(x -> parse(Int, x), split(l))
        push!(source, Interval{Closed, Open}(l[2], l[2] + l[3]))
        push!(diff, l[1] - l[2])
    end
    push!(source, Interval{Closed, Open}(0, minimum(map(x -> first(x), source))))
    push!(source, Interval{Closed, Open}(maximum(map(x -> last(x), source)), typemax(Int)))
    for _ in 1:2 push!(diff, 0) end
    curr = Vector{Interval{Int, Closed, Open}}()
    for intv in start
        for i in eachindex(source)
            sect = intv ∩ source[i]
            if !isempty(sect)
                push!(curr, Interval{Closed, Open}(
                    first(intv) + diff[i], 
                    last(intv) + diff[i]
                ))
            end
        end
    end
    global start = →(curr)
end
println(start)