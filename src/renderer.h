namespace XGK
{
  struct Material
  {
    // inline static size_t index {};
  };

  struct MaterialVulkan : public Material
  {};

  struct MaterialOpengl : public Material
  {};

  // struct MaterialWebgpu
  // {};

  struct Renderer
  {
    Renderer (void);
    Renderer (const Renderer&&);
    virtual ~Renderer (void);

    void operator = (const Renderer&&);



    // size_t window_width {};
    // size_t window_height {};
    // samples;


    // Abstract type;
    // virtual Material& createMaterial (void) = 0;
    // virtual void render (void) = 0;

    virtual Material& createMaterial (void);
    virtual void render (void);
  };

  struct RendererVulkan : public Renderer
  {
    virtual Material& createMaterial (void) override;
    virtual void render (void) override;
  };

  struct RendererOpengl : public Renderer
  {
    virtual Material& createMaterial (void) override;
    virtual void render (void) override;
  };

  Material& RendererVulkan::createMaterial ()
  {
    MaterialVulkan material {};

    return material;
  }

  Material& RendererOpengl::createMaterial ()
  {
    MaterialOpengl material {};

    return material;
  }

  struct Object
  {
    Material* material;
  };
}

XGK::Renderer renderer {};

void test (void)
{
  // XGK::RendererVulkan _renderer {};

  renderer = XGK::RendererVulkan();

  renderer.~Renderer();
}
