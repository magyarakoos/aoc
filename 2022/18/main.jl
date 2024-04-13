σ = Set()
λ = (m) -> push!(σ, (m[1], m[2], m[3]))
Ψ = (x, y, z) -> [(x+1, y, z), (x-1, y, z), (x, y+1, z), (x, y-1, z), (x, y, z+1), (x, y, z-1)]
map(l -> λ(map(x -> parse(Int, x), match(r"(\d+),(\d+),(\d+)", l))), readlines("input"))
Σ = length(σ) * 6; mxx = 0; mxy = 0; mxz = 0
for (x, y, z) in σ, ρ in Ψ(x, y, z)
    if ∈(ρ, σ)
        global Σ -= 1
    end
    global mxx = max(mxx, x)
    global mxy = max(mxy, y)
    global mxz = max(mxz, z)
end
println(Σ)
println((mxx, mxy, mxz))