module NavigationLink = {
  [@react.component]
  let make = (~_to, ~text) => {
    let parts =
      Breadcrumbs.JsWindow.location
      |> Breadcrumbs.split_on_char('/')
      |> List.tl
      |> List.hd;

    let isActive = "/" ++ parts == _to;

    <Gatsby.Link
      className={
        Some(
          Css.merge([
            "border-t-4 text-white text-lg font-normal mr-6 last:mr-0 py-8 flex justify-center
                    items-center",
            isActive ? "border-white" : "border-transparent",
          ]),
        )
      }
      _to>
      text->React.string
    </Gatsby.Link>;
  };
};

[@react.component]
let make = () => {
  <nav className="col-start-2 bg-transparent flex items-start">
    <div className="flex ml-auto">
      <NavigationLink _to="/erbjudanden" text="Erbjudanden" />
      <NavigationLink _to="/case" text={j|Våra case|j} />
      <NavigationLink _to="/hur-vi-jobbar" text="Metod" />
      <NavigationLink _to="/medarbetare" text="Medarbetare" />
      <NavigationLink _to="/karriar" text={j|Karriär|j} />
      <NavigationLink _to="/om-oss" text="Om" />
    </div>
  </nav>;
};
