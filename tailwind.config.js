module.exports = {
  theme: {
    screens: {
      mobile: { max: '640px' },
      tablet: { max: '768px' },
      sm: '640px', // => @media (min-width: 640px) { ... }
      md: '769px', // => @media (min-width: 768px) { ... }
      lg: '1025px', // => @media (min-width: 1024px) { ... }
      xl: '1280px', // => @media (min-width: 1280px) { ... }
    },
    extend: {
      colors: {
        aquamarine: 'hsl(152, 95%, 66%)', // #54fbac
        concrete: 'hsl(0, 4%, 95%)', // #f3f2f2
        'cornflower-blue': 'hsl(225, 100%, 70%)', // #668cff
        'radical-red': 'hsl(350, 100%, 62%)', // #ff3b5c
        current: 'currentcolor',
        white: 'white',
      },
      maxWidth: {
        initial: 'initial',
      },
    },
    fontFamily: {
      sans: ['Roboto', 'sans-serif'],
    },
    height: {
      32: '8rem',
      md: '430px',
      startpage2019: '720px',
      jumbo: '800px',
    },
  },
  variants: {},
  plugins: [
    require('tailwindcss-grid')({
      grids: [2, 3, 4, 5, 6, 8, 10, 12],
      gaps: {
        '5': '1.25rem',
        '8': '2rem',
        '8-x': '2rem',
        '2-y': '0.75rem',
        '4-y': '1rem',
        '10-y': '2.5rem',
        '12-y': '3rem',
        '24-y': '6rem',
      },
      autoMinWidths: {
        '16': '4rem',
        '24': '6rem',
        '300px': '300px',
      },
      variants: ['responsive'],
    }),
  ],
}
