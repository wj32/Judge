let buy free w =
  let rec loop acc = function
    | [] -> acc
    | x :: rest -> loop (acc + 1) (List.skipWhile ((>=) (x + free)) rest)
  loop 0 (List.sort w)

let n = stdin.ReadLine() |> int
let w = stdin.ReadLine().Split(' ') |> Seq.map int |> Seq.toList
printfn "%d" (buy 4 w)
