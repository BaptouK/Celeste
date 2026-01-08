#version 430 core

//Input
layout (location=0) in vec2 texturCoordsIn;

// Output
layout (location = 0) out vec4 fragColor;

// Bindings
layout (location = 0) uniform sampler2D textureAtlas;


void main(){
    vec4 textureColor = texelFetch(textureAtlas, ivec2(texturCoordsIn),0);

    if(textureColor.a == 0.0){
        discard;
    }

    fragColor = textureColor;
}