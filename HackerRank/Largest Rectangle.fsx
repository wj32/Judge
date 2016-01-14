open System

let n = Console.ReadLine() |> int
let h =
  [[0L] :> int64 seq; Console.ReadLine().Split(' ') |> Seq.map int64; [0L] :> int64 seq]
  |> Seq.concat
  |> Seq.toArray
let mutable unmatched = []
let mutable maxArea = 0L

for i = 0 to n + 1 do
  let rec loop () =
    match unmatched with
    | j :: rest when h.[j] > h.[i] ->
      let k = List.head rest
      maxArea <- max maxArea (h.[j] * int64 (i - k - 1))
      unmatched <- rest
      loop ()
    | _ ->
      unmatched <- i :: unmatched
  loop ()

printfn "%d" maxArea
