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
  })
}
