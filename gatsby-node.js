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

exports.sourceNodes = ({ actions }) => {
  const { createTypes } = actions

  const typeDefs = `
    type AboutUsTextNode {
      aboutUs: String
    }

    type ApplicationTextNode {
      application: String
    }

    type BonusKnowledgeTextNode {
      bonusKnowledge: String
    }

    type KnowledgeTextNode {
      knowledge: String
    }

    type PerksTextNode {
      perks: String
    }

    type RoleTextNode {
      id: ID!
      role: String
    }

    type TechnicalitiesTextNode {
      technicalities: String
    }

    type ContentfulAnnonser implements Node {
      aboutUsTitle: String
      aboutUs: AboutUsTextNode
      applicationTitle: String
      application: ApplicationTextNode
      bonusKnowledgeTitle: String
      bonusKnowledge: BonusKnowledgeTextNode
      contacts: [ContentfulKollegor]
      contactTitle: String
      headerText1: String
      headerText2: String
      headerTextBgColor: String
      headerImage: ContentfulAsset
      id: ID!
      knowledgeTitle: String
      knowledge: KnowledgeTextNode
      location: String
      node_locale: String!
      perksTitle: String
      perks: PerksTextNode
      roleTitle: String
      role: RoleTextNode
      technicalitiesTitle: String
      technicalities: TechnicalitiesTextNode
      title: String
      urlId: String
    }
  `

  createTypes(typeDefs)
}

exports.createResolvers = ({ createResolvers, schema }) => {
  createResolvers({
    Query: {
      allContentfulAnnonser: {
        type: `[ContentfulAnnonser!]!`,
        resolve(source, args, context, info) {
          return []
        },
      },
    },
  })
}
