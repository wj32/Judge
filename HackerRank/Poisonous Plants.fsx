open System

let n = Console.ReadLine() |> int
let p = Console.ReadLine().Split(' ') |> Array.map int

let mutable s = []
let mutable maxLevel = 0

for i = 0 to n - 1 do
  let rec loop level =
    match s with
    | (x, l) :: rest ->
      if x >= p.[i] then
        s <- rest
        loop (max level l)
      else
        let l' = level + 1
        s <- (p.[i], l') :: s
        if maxLevel < l' then
          maxLevel <- l'
    | [] ->
      s <- (p.[i], 0) :: s
  loop 0

printfn "%d" maxLevel
