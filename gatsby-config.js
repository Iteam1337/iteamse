const path = require('path')

const activeEnv =
  process.env.GATSBY_ACTIVE_ENV || process.env.NODE_ENV || 'development'

require('dotenv').config({
  path: `.env.${activeEnv}`,
})

module.exports = {
  siteMetadata: {
    title: 'Iteam',
  },
  plugins: [
    'gatsby-plugin-react-helmet',
    'gatsby-plugin-postcss',
    {
      resolve: `gatsby-source-filesystem`,
      options: {
        name: `images`,
        path: path.join(__dirname, `src`, `images`),
      },
    },
    `gatsby-plugin-sharp`,
    `gatsby-transformer-sharp`,
    {
      resolve: `gatsby-plugin-google-fonts`,
      options: {
        fonts: [`roboto:300,400,500,700`],
        display: 'swap',
      },
    },
    {
      resolve: `gatsby-source-ghost`,
      options: {
        apiUrl: `https://blog.iteam.life`,
        contentApiKey: process.env.GHOST_CONTENT_API,
        version: `v2`,
      },
    },
    {
      resolve: `gatsby-source-contentful`,
      options: {
        spaceId: process.env.CONTENTFUL_SPACE,
        accessToken: process.env.CONTENTFUL_ACCESS_TOKEN,
        downloadLocal: true,
      },
    },
    {
      resolve: `gatsby-plugin-manifest`,
      options: {
        name: `Iteam`,
        short_name: `Iteam`,
        start_url: `/`,
        background_color: `#ffffff`,
        theme_color: `#668cff`,
        display: `standalone`,
        icon: `src/images/favicon.png`,
      },
    },
  ],
}
