open System

let n = Console.ReadLine() |> int
let mutable stack = []
let mutable maxStack = []

for _ in { 1 .. n } do
  match Console.ReadLine().Split(' ') |> Array.map int with
  | [|1; x|] ->
    stack <- x :: stack
    maxStack <- max x (defaultArg (List.tryHead maxStack) x) :: maxStack
  | [|2|] ->
    stack <- List.tail stack
    maxStack <- List.tail maxStack
  | [|3|] ->
    printfn "%d" (List.head maxStack)
  | _ ->
    failwith "Invalid input"
