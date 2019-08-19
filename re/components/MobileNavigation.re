type state =
  | NavigationIsVisible
  | NavigationIsHidden;

module MenuButton = {
  let className =
    Css.(
      style([
        backgroundColor(`hex("fff")),
        borderRadius(`percent(100.0)),
        borderWidth(`zero),
        bottom(`px(20)),
        boxShadow(
          ~x=`zero,
          ~y=`px(2),
          ~blur=`px(4),
          `rgba((0, 0, 0, 0.2)),
        ),
        height(`px(60)),
        position(`fixed),
        right(`px(20)),
        width(`px(60)),
        zIndex(2),
        focus([outlineWidth(`zero)]),
        media(
          "only screen and (device-width: 375px) and (device-height: 812px)
                   and (-webkit-device-pixel-ratio: 3)",
          [bottom(`zero), top(`px(20))],
        ),
        media(
          Theme.Breakpoints.fromType(`Tablet),
          [bottom(`px(20)), right(`px(20))],
        ),
      ])
    );

  [@react.component]
  let make = (~children, ~onClick) => {
    <button className onClick type_="button"> children </button>;
  };
};

module Bar = {
  let className = navigationState =>
    Css.(
      style([
        height(`px(2)),
        width(`px(25)),
        backgroundColor(`hex("000")),
        margin2(~v=`px(5), ~h=`auto),
        transition(~duration=150, ~timingFunction=`easeInOut, "all"),
        firstChild([
          navigationState === NavigationIsVisible
            ? transforms([`translateY(`px(7)), `rotate(`deg(45.0))])
            : transforms([`translateY(`px(0)), `rotate(`deg(0.0))]),
        ]),
        selector(
          "&:nth-child(2)",
          [
            navigationState === NavigationIsVisible
              ? opacity(0.0) : opacity(100.0),
          ],
        ),
        lastChild([
          navigationState === NavigationIsVisible
            ? transforms([`translateY(`px(-7)), `rotate(`deg(-45.0))])
            : transforms([`translateY(`px(0)), `rotate(`deg(0.0))]),
        ]),
      ])
    );

  [@react.component]
  let make = (~navigationState) => {
    <div className={className(navigationState)} />;
  };
};

[@react.component]
let make = () => {
  let (navigationState, updateNavigationState) =
    React.useState(() => NavigationIsHidden);

  <div className="md:hidden">
    {switch (navigationState) {
     | NavigationIsHidden => React.null
     | NavigationIsVisible =>
       <div
         className="fixed inset-0 bg-white text-right grid items-end px-5 pb-32">
         <nav className="grid grid-gap-10-y">
           {Navigation.Options.items
            ->Belt.List.map(({link, text}) =>
                <Gatsby.Link
                  className={
                    Some(
                      "text-black text-2xl border-b-2 border-black justify-self-end",
                    )
                  }
                  _to=link>
                  {React.string(text)}
                </Gatsby.Link>
              )
            ->Belt.List.toArray
            ->React.array}
         </nav>
       </div>
     }}
    <MenuButton
      onClick={_ =>
        updateNavigationState(current =>
          current === NavigationIsVisible
            ? NavigationIsHidden : NavigationIsVisible
        )
      }>
      <div>
        <Bar navigationState />
        <Bar navigationState />
        <Bar navigationState />
      </div>
    </MenuButton>
  </div>;
};

let default = make;
