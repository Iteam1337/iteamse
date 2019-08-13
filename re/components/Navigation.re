module NavigationLink = {
  [@react.component]
  let make = (~_to, ~text, ~color) => {
    let parts =
      Breadcrumbs.JsWindow.location
      |> Breadcrumbs.split_on_char('/')
      |> List.tl
      |> List.hd;

    let isActive = "/" ++ parts == _to;

    let textColor =
      switch (color) {
      | `White => "text-white"
      | `Black => "text-black"
      };

    <Gatsby.Link
      className={
        Some(
          Css.merge([
            "border-t-4 text-lg font-normal mr-6 last:mr-0 py-8 flex justify-center items-center border-transparent",
            "border-white"->Cn.ifTrue(isActive),
            textColor,
          ]),
        )
      }
      _to>
      text->React.string
    </Gatsby.Link>;
  };
};

[@react.component]
let make = (~color=`White) => {
  <div className="col-start-2 bg-transparent flex flex-1 items-start">
    <Logo color />
    <nav className="flex ml-auto">
      <NavigationLink color _to="/erbjudanden" text="Erbjudanden" />
      <NavigationLink color _to="/case" text={j|Våra case|j} />
      <NavigationLink color _to="/hur-vi-jobbar" text="Metod" />
      <NavigationLink color _to="/medarbetare" text="Medarbetare" />
      <NavigationLink color _to="/karriar" text={j|Karriär|j} />
      <NavigationLink color _to="/om-oss" text="Om" />
    </nav>
  </div>;
};
