module SimpleQueryText = [%graphql
  {|
query someRandomName($pokemonName: String!) {
    pokemon(where: {name: {_ilike: $pokemonName}}) {
      name
      image
    }
}
|}
];

module SimpleQuery = ReasonApolloHooks.Query.Make(SimpleQueryText);

[@react.component]
let make = (~pokemonName: string) => {
  let variables =
    Js.Json.object_(
      Js.Dict.fromList([
        ("pokemonName", Js.Json.string(pokemonName ++ "%")),
      ]),
    );
  // let (_simple, full) = SimpleQuery.use(~variables=pokemonName, ());
  let (simple, _full) = SimpleQuery.use(~variables, ());
  print_string(pokemonName);
  let renderPokemon = pokemon =>
    <div
      key={
        pokemon##name;
      }
      style={ReactDOMRe.Style.make(
        ~fontFamily="IBM Plex Mono",
        ~fontStyle="italic",
        ~textAlign="center",
        (),
      )}>
      <h2 style={ReactDOMRe.Style.make(~fontSize="2em", ())}>
        {React.string(pokemon##name)}
      </h2>
      <img src=pokemon##image />
    </div>;
  switch (simple) {
  | Data(data) =>
    let pokemonList =
      Array.map(pokemon => renderPokemon(pokemon), data##pokemon);
    <div
      style={ReactDOMRe.Style.make(
        ~display="grid",
        ~gridTemplateColumns="repeat(3, 1fr)",
        ~gridColumnGap="1rem",
        (),
      )}>
      {React.array(pokemonList)}
    </div>;
  | Loading => React.string("loading")
  | NoData => React.string("noData")
  | Error(_) => React.string("error")
  };
};

/* For using variables in query

    - add variable to gql query string

   `query someRandomName($nameOfVariable: String!) {
      pokemon(limit:$nameOfVariable)
      ...
   `

    - and pass object with varialbes to hook

    let variables: Js.Json.t = {"nameOfVariable": "valueOfVariable"}->Obj.magic;
    let (simple, _full) = SimpleQuery.use(~variables, ());
    */