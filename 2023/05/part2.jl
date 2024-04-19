using Intervals

f = open("input", "r")
start = Vector{Interval{Int, Closed, Open}}()
m = map(x -> parse(Int, x), split(match(r"\S+(.*)", readline(f))[1]))
for i in 2:2:length(m)
    push!(start, Interval{Closed, Open}(m[i - 1], m[i - 1] + m[i]))
end

function collapse(intvs::Vector{Interval{Int, Closed, Open}})
    sort!(intvs)
    result = Interval[]
    curr = intvs[1]
    for intv in intvs[2:end]
        if curr ∩ intv != empty
            curr = curr ∪ intv
        else
            push!(result, curr)
            curr = intv
        end
    end
    push!(result, curr)
    return result
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
    global start = collapse(copy(curr))
end
println(start)