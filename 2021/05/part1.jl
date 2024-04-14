m = zeros(Int, 1000, 1000)
λ = (x1, y1, x2, y2) -> begin
    for in
end
map((x1, y1, x2, y2) -> λ(x1, y1, x2, y2), 
    where((x1, y1, x2, y2) -> x1 == x2 || y1 == y2, 
    map(l -> map(x -> (x[1], x[2], x[3], x[4]), 
        match(r"(\d+),(\d+) -> (\d+),(\d+)", l)), 
    readlines("input")
)))