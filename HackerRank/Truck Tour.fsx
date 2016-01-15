open System
open System.Collections.Generic

let n = Console.ReadLine() |> int

let pumps =
  seq {1 .. n}
  |> Seq.map (fun _ ->
    match Console.ReadLine().Split(' ') |> Array.map int with
    | [|p; d|] -> (p, d)
    | _ -> failwith "Invalid input")
  |> Seq.toArray

let rec solution petrol i j =
  let j' = (j + 1) % n
  if i = j' then
    i
  else
    let distance = snd pumps.[j]
    if petrol >= distance then
      let petrol' = petrol - distance + fst pumps.[j']
      solution petrol' i j'
    else
      let i' = (i + 1) % n
      if i <> j then
        let petrol' = petrol + snd pumps.[i] - fst pumps.[i]
        solution petrol' i' j
      else
        solution (fst pumps.[i']) i' i'

printfn "%d" (solution (fst pumps.[0]) 0 0)
