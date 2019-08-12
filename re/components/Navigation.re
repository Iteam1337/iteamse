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
            "border-t-4 text-white text-lg font-normal mr-6 last:mr-0 py-8 flex justify-center items-center border-transparent",
            "border-white"->Cn.ifTrue(isActive),
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
  <div className="col-start-2 bg-transparent flex flex-1 items-start">
    <Gatsby.Link className={Some("py-8")} _to="/">
      <img src="/image/iteam-logo.svg" alt="Iteam Logotype" />
    </Gatsby.Link>
    <nav className="flex ml-auto">
      <NavigationLink _to="/erbjudanden" text="Erbjudanden" />
      <NavigationLink _to="/case" text={j|Våra case|j} />
      <NavigationLink _to="/hur-vi-jobbar" text="Metod" />
      <NavigationLink _to="/medarbetare" text="Medarbetare" />
      <NavigationLink _to="/karriar" text={j|Karriär|j} />
      <NavigationLink _to="/om-oss" text="Om" />
    </nav>
  </div>;
};
