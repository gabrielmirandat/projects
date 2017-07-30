Classe principal para cenas 3D
	mrpt::opengl::COpenGLScene: allows the user to create, load, save, and render 3D scenes using OpenGL primitives.
	An object of COpenGLScene always contains at least one viewport (mrpt::opengl::COpenGLViewport), named "main"

	User will not call COpenGLScene::render(), but the 3D standalone viewer (SceneViewer)

	An object COpenGLScene can be saved to a “.3Dscene” file using COpenGLScene::saveToFile(), for posterior visualization from the 
	standalone application SceneViewer.

	Veja http://reference.mrpt.org/devel/group__mrpt__opengl__grp.html