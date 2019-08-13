const path = require('path')

exports.createPages = ({ graphql, actions }) => {
  const { createPage } = actions

  return graphql(`
    {
      allContentfulKollegor(
        filter: { node_locale: { eq: "sv-SE" } }
        sort: { order: ASC, fields: name }
      ) {
        nodes {
          short
        }
      }
      allContentfulAnnonser(filter: { node_locale: { eq: "sv-SE" } }) {
        nodes {
          urlId
        }
      }
      allContentfulProjekt(filter: { node_locale: { eq: "sv-SE" } }) {
        nodes {
          slug
        }
      }
    }
  `).then(result => {
    result.data.allContentfulKollegor.nodes.forEach(node => {
      createPage({
        path: `/medarbetare/${node.short}`,
        component: path.resolve('./src/templates/coworker.js'),
        context: {
          short: node.short,
        },
      })
    })

    result.data.allContentfulAnnonser.nodes.forEach(node => {
      createPage({
        path: `/karriar/${node.urlId}`,
        component: path.resolve('./src/templates/opportunity.js'),
        context: {
          urlId: node.urlId,
        },
      })
    })

    result.data.allContentfulProjekt.nodes.forEach(node => {
      createPage({
        path: `/case/${node.slug}`,
        component: path.resolve('./src/templates/case.js'),
        context: {
          slug: node.slug,
        },
      })
    })
  })
}
