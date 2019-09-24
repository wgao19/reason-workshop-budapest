let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let httpLink =
  ApolloLinks.createHttpLink(
    ~uri="https://pokura.matystl.now.sh/api/graphql",
    //~uri="http://104.154.18.109/v1/graphql",
    (),
  );

let client =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());

[@react.component]
let make = () => {
  let (pokemonName, setPokemonName) = React.useState(() => "");
  let onChange = e => setPokemonName(e->ReactEvent.Form.target##value);
  <ReasonApollo.Provider client>
    <ReasonApolloHooks.ApolloProvider client>
      <input
        value=pokemonName
        onChange
        style={ReactDOMRe.Style.make(
          ~border="1px solid #222",
          ~borderRadius="2px",
          ~boxShadow="#222 2px 2px 0 0",
          ~width="calc(100% - 1em)",
          ~height="3rem",
          ~fontSize="2rem",
          ~padding=".5em",
          ~fontFamily="IBM Plex Mono",
          (),
        )}
      />
      <PokemonExample pokemonName />
    </ReasonApolloHooks.ApolloProvider>
  </ReasonApollo.Provider>;
};