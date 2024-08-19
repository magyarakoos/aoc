# the idea is correct, but I failed implementation.

using IntervalSets
using Base: intersect

mutable struct Part
    x::ClosedInterval{Int}
    m::ClosedInterval{Int}
    a::ClosedInterval{Int}
    s::ClosedInterval{Int}
    function Part(x::ClosedInterval{Int}, m::ClosedInterval{Int}, a::ClosedInterval{Int}, s::ClosedInterval{Int})
        new(x, m, a, s)
    end
    function Part(x::Tuple{Int,Int}, m::Tuple{Int,Int}, a::Tuple{Int,Int}, s::Tuple{Int,Int})
        new(ClosedInterval(x...), ClosedInterval(m...), ClosedInterval(a...), ClosedInterval(s...))
    end
    function Part()
        Part((1, 4000), (1, 4000), (1, 4000), (1, 4000))
    end
    function Part(prop::Char, op::Char, val::Int)
        obj = Part()
        intv = ClosedInterval((op == '<' ? (1, val - 1) : (val + 1, 4000))...)
        if prop == 'x'
            obj.x = intv
        elseif prop == 'm'
            obj.m = intv
        elseif prop == 'a'
            obj.a = intv
        elseif prop == 's'
            obj.s = intv
        end
        return obj
    end
end

len(intv::ClosedInterval{Int}) = endpoints(intv)[2] - endpoints(intv)[1] + 1
intersect_all(a::Part, b::Part) = Part(intersect(a.x, b.x), intersect(a.m, b.m), intersect(a.a, b.a), intersect(a.s, b.s))
inverse = (intv::ClosedInterval{Int}) -> begin
    ep = endpoints(intv)
    if ep == (1, 4000)
        return intv
    elseif ep[1] == 1
        return ClosedInterval(ep[2] + 1, 4000)
    else
        return ClosedInterval(1, ep[1] - 1)
    end
end
inverse_all(p::Part) = Part(inverse(p.x), inverse(p.m), inverse(p.a), inverse(p.s))

g = Dict{String,Vector{Tuple{Part,String}}}()
f = readlines("input")
r = r"(\w+){([xmas])([<>])(\d+):(\w+)(?:,([xmas])([<>])(\d+):(\w+))*,(\w+)}"
p2 = 0

for m in map(l -> match(r, l), f[1:findfirst(s -> s == "", f)-1])
    g[m[1]] = Vector{Tuple{Part,String}}()
    for i in 5:4:length(m)-1
        if m[i] === nothing
            break
        end
        push!(g[m[1]], (Part(m[i-3][1], m[i-2][1], parse(Int, m[i-1])), m[i]))
    end
    push!(g[m[1]], (Part(), m[length(m)]))
end

function dfs(u::String, p::Part)
    if u == "R"
        return
    end
    if u == "A"
        global p2 += len(p.x) * len(p.m) * len(p.a) * len(p.s)
        return
    end
    for (q, v) in g[u]
        dfs(v, intersect_all(p, q))
        p = intersect_all(p, inverse_all(q))
    end
end

dfs("in", Part())
println(p2)
