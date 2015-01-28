#include "ObjLoader.hpp"


ObjLoader::ObjLoader(void)
{
}


ObjLoader::~ObjLoader(void)
{
}

void ObjLoader::loadObj(const char* filename, std::vector<glm::vec3> &vertices, std::vector<glm::vec3> &normals, std::vector<glm::vec2> &uvs)
{
	std::vector<unsigned int> vertexIndices, vertexTextureIndices, normalIndices;
	std::vector<glm::vec3> tempVertices;
	std::vector<glm::vec3> tempVertexNormals;
    std::vector<glm::vec2> tempUvs;

	FILE* file;
	errno = fopen_s( &file, filename, "r" );

	if ( errno )
	{
		std::cerr << "File not found" << filename << std::endl;
		exit( 1 );
	}

	while ( 1 )
	{
		char line[32];

		int res = fscanf( file, "%s", line, sizeof(line));


		if ( res == -1 )
		{
			break;
		}

		else if ( strcmp( line, "v" ) == 0 )
		{
			glm::vec3 vertex;
			fscanf( file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
			tempVertices.push_back( vertex );
		}
		else if ( strcmp(line, "vt") == 0 )
		{
			glm::vec2 tex;
			fscanf( file, "%f %f\n", &tex.x, &tex.y );
			tempUvs.push_back(tex);
		}
		else if ( strcmp(line, "vn") == 0 )
		{
			glm::vec3 normal;
			fscanf( file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
			tempVertexNormals.push_back( normal );
		}
		else if ( strcmp(line, "f") == 0 )
		{
			unsigned int tempVertexIndex[3], tempUvIndex[3], tempNormalIndex[3];

			fscanf( file, "%d/%d %d/%d %d/%d\n",
					&tempVertexIndex[0], &tempUvIndex[0],
					&tempVertexIndex[1], &tempUvIndex[1], 
					&tempVertexIndex[2], &tempUvIndex[2]
					);
			vertexIndices.push_back( tempVertexIndex[0] );
			vertexTextureIndices.push_back( tempUvIndex[0] );
			normalIndices.push_back( tempNormalIndex[0] );

			vertexIndices.push_back( tempVertexIndex[1] );
			vertexTextureIndices.push_back( tempUvIndex[1] );
			normalIndices.push_back( tempNormalIndex[1] );

			vertexIndices.push_back( tempVertexIndex[2] );
			vertexTextureIndices.push_back( tempUvIndex[2] );
			normalIndices.push_back( tempNormalIndex[2] );
		}
	}

	for ( unsigned int i = 0; i < vertexIndices.size(); i++ )
	{
		glm::vec3 vertex = tempVertices[vertexIndices[i] - 1];
		vertices.push_back( vertex );
	}

    for (unsigned int i = 0; i < vertexTextureIndices.size(); i++)
    {
        glm::vec2 uv = tempUvs[vertexTextureIndices[i] - 1];
        uvs.push_back(uv);
    }
}

void ObjLoader::loadTexture()
{
    glload::LoadTest loadTest = glload::LoadFunctions();

    try
    {
        std::auto_ptr<glimg::ImageSet> pImageSet(glimg::loaders::stb::LoadFromFile("tex_wendy.jpg"));
        textureID = glimg::CreateTexture(pImageSet.get(), 0);
    }
    catch(glimg::loaders::stb::StbLoaderException &e)
    {
        std::cerr << "Failed to load Texture\n";
    }
    catch(glimg::TextureGenerationException &e)
    {
        std::cerr << "Texture Generatiion failed\n";
    }
}

void ObjLoader::loadVBOData(std::vector<glm::vec3> &vertices, std::vector<glm::vec2> &uvs)
{
    glGenBuffers(1, &vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &uvBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, uvBufferID);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
}
